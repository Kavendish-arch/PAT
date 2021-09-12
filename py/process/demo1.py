# encoding=utf-8
import requests
import pymongo
import pprint
import re

from requests.api import options

page = requests.get("https://www.amazon.cn/")
pa = re.compile(r'<option.+>(.+?)</option>')
options = re.findall(pa, page.text)
for i in options:
    print(i)