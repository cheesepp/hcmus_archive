# from bs4 import BeautifulSoup
# import requests

# def find_files(url):

#     soup = BeautifulSoup(requests.get(url).text, features = "html.parser")

#     for a in soup.find_all('a'):
#         yield a['href']

# for link in find_files("http://web.stanford.edu/class/cs142/lectures/"):
#     if '.' in link:
#      print(link)
#!/usr/bin/env python3

from bs4 import BeautifulSoup
import os
import requests
from requests import get

main_url = input('Enter URL: ')
page = requests.get(main_url)
filetype = '.' + input('Enter File Extension (with no dot): ')
soup = BeautifulSoup(page.text, 'html.parser')
directory = main_url.split("/")[-2]
print(directory)
if not os.path.isdir(directory):
  os.mkdir(directory) 

for link in soup.find_all('a'):
    url = link.get('href')
    if filetype in url:
        print(main_url + url)
        with open(url, 'wb') as file:
            response = get(main_url + url)
            file.write(response.content)
    else:
        continue