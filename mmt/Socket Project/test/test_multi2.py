import asyncio
import os
import os.path
import time
import aiohttp
from bs4 import BeautifulSoup

main_url = input('Enter URL: ')
ext = '.' + input('Enter File Extension (with no dot): ')


async def fetch_download_links(session: aiohttp.ClientSession, url: str):
    response = await session.get(url)
    if response.ok:
        response_text = await response.text()
        print(response_text)
    else:
        return response.raise_for_status()
    soup = BeautifulSoup(response_text, 'html.parser')

    directory = url.split("/")[-2]
    print(directory)
    if not os.path.isdir(directory):
        os.mkdir(directory)
    parent = [url + node.get('href') for node in soup.find_all('a')
              if node.get('href').endswith(ext)]
    return (parent, directory)


async def place_file(session: aiohttp.ClientSession, source: str, directory) -> None:
    r = await session.get(source)

    f_name = source.split("/")[-1]
    with open(os.path.join(directory, f_name), 'wb') as f:
        async for data in r.content.iter_any():
            f.write(data)
        print(f_name)


async def main():
    async with aiohttp.ClientSession() as session:
        (urls,directory) = await fetch_download_links(session, main_url)
        await asyncio.gather(*[place_file(session, url, directory) for url in urls])


if __name__ == '__main__':
    t1 = time.perf_counter()
    print('process started...')
    asyncio.get_event_loop().run_until_complete(main())
    t2 = time.perf_counter()
    print(f'Completed in {t2-t1} seconds.')