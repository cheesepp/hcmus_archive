import requests
import os
import threading
import time
from bs4 import BeautifulSoup
import aiohttp
import asyncio
import urllib


def get_url_paths(url, ext=''):
    response = requests.get(url)
    # response = requests.get(url, auth=HTTPBasicAuth('username', 'password'))
    if response.ok:
        response_text = response.text
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


def main():
    main_url = input('Enter URL: ')
    ext = '.' + input('Enter File Extension (with no dot): ')
    # url = 'http://wwlln.net/hostdata//'
    t1 = time.perf_counter()
    # ext = '.loc'
    (result, directory) = get_url_paths(main_url, ext)
    for file in result:
        f_name = file.split("/")[-1]
        createNewDownloadThread(file, directory, f_name)
    print('closed!')
    t2 = time.perf_counter()
    print(f'Completed in {t2-t1} seconds.')


def download(file, directory, f_name):
    print('loading...')
    r = requests.get(file, stream=True)
    # r = requests.get(file, auth=HTTPBasicAuth('username', 'password'))
    with open(f'{directory}/{f_name}', 'wb') as f:
        for chunk in r.iter_content(1024):
            if chunk:
                f.write(chunk)
    print('loaded!')
    print(f_name)


def createNewDownloadThread(file, directory, f_name):
    download_thread = threading.Thread(target=download, args=(file, directory, f_name))
    download_thread.start()


# for i in range(0,5):
#     file = "C:\\test" + str(i) + ".png"
#     print file
#     createNewDownloadThread("http://stackoverflow.com/users/flair/2374517.png", file)
main()

