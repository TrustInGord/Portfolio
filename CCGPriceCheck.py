from selenium import webdriver
import smtplib
import time
from datetime import datetime

webaddy = "https://www.unrealengine.com/marketplace/en-US/product/ccg-toolkit"

def check_price():

    price_limit = '49.99'

    #Open Browser
    browser = webdriver.Chrome(executable_path=r"C:\Users\Gordon\AppData\Local\Programs\Python\Python38-32\chromedriver.exe")
    browser.get(webaddy)

    #Search for element and put in variable
    elem = browser.find_element_by_css_selector('.post-title')
    prices = browser.find_element_by_css_selector('.price_inside_buybox')


    #search_field = browser.find_element_by_css_selector("#price_inside_buybox")

    #browser.find_element_by_css_selector(body > div.main > div:nth-child(1) > div:nth-child(2) > a)

    #Test Variable to see if we got anything.
    print("Variable Phase")

    print(elem.text())
    print(prices.text())

    print("Transfer to meow")
    titleText = elem.text()
    priceText = prices.text.strip('$')

    print(priceText)

    browser.quit()
    print(datetime.now())

#Amzon Stripping
#    print("\nMeow Stripped")
#    priceText = meow.strip("CDN$ ")
#    print(priceText)

#Price Compare
    print("Price comparator")
    if (priceText >= price_limit):
        print("Darn, wait a bit")

    if (priceText < price_limit):
        print("Price is lower ")
        send_mail()

        
#Send to email        
def send_mail():
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.ehlo()
    
    uremail = ""
    urpass = ""

    server.login('uremail', 'urpass')

    subject = 'Price Fell Down!'
    body = f'Check the Amazon link {webaddy}'

    msg = f"Subject: {subject}\n\n{body}"

    server.sendmail(
        'uremail',
        msg
    )

    print("Email Sent with Price Drop")

    server.quit()


while(True):
    check_price()
    time.sleep(60 * 60 * 24)
#    time.sleep(60 * 60 * 24)
