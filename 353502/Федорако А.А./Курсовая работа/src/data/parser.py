from selenium import webdriver
from bs4 import BeautifulSoup
import sqlite3
import time

connection = sqlite3.connect('my_database.db')
cursor = connection.cursor()
browser = webdriver.Chrome()
browser.get("https://infoprice.by/?goods=3286")
time.sleep(1)
cursor = connection.cursor()

cursor.execute('''
CREATE TABLE IF NOT EXISTS Products (
id INTEGER PRIMARY KEY,
name TEXT NOT NULL,
category TEXT NOT NULL,
picture TEXT NOT NULL,
url TEXT NOT NULL,
first_price TEXT NOT NULL,
second_price TEXT NOT NULL,
third_price TEXT NOT NULL,
fourth_price TEXT NOT NULL,
fifth_price TEXT NOT NULL,
sixth_price TEXT NOT NULL,
seventh_price TEXT NOT NULL
)
''')

page_source = browser.page_source
soup = BeautifulSoup(page_source, 'html.parser')
data = soup.find("div", class_="page-wrapper").find("div", id="app").find("div", class_ = "content-wrapper").find("div", class_="compare-table tag-bloks").find("div", class_="body-table syncscroll")

data2 = data.find_all("div", class_="column-item")
namelist = data2[0].find_all("div", class_="product")
prices = []

for i in range(1, 8):
    prices.append(data2[i].find_all("div", class_="price"))

m = dict()

for i in range (len(namelist)):
    obg = namelist[i]
    namestr = obg.find("div", class_="description").find("div", class_="max-height").string
    style = obg.find("div", class_="img-warp").find("div", class_="img img-background")['style'].split('"')[1]
    m[namestr] = [style]
    for j in range(7):
        a = prices[j][i].find("div", class_="price-volume")
        if a != None:
            m[namestr].append(a.string)
        else:
            m[namestr].append('-')

# change_start !
for i, (key, value) in enumerate(m.items(), start=46):
    name = key
    picture = "image" + str(i)
    category = "Вино импортное"
    url = value[0]
    insert_data = (name, category, picture, str(url), str(value[1]), str(value[2]), str(value[3]), str(value[4]), str(value[5]), str(value[6]), str(value[7]))
    cursor.execute('INSERT INTO Products (name, category, picture, url,  first_price, second_price, third_price, fourth_price, fifth_price, sixth_price, seventh_price) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)', insert_data)

browser.quit()
connection.commit()
connection.close()
