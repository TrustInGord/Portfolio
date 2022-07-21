#Checks an Unreal Store the 

from selenium import webdriver
import smtplib
import time
from datetime import datetime

webaddy = "https://www.unrealengine.com/marketplace/en-US/product/ccg-toolkit"

def check_price():

    #Change Price as needed
    price_limit = '49.99'

    
    #Chrome Driver
    CDrive = ""
    
    #Open Browser
    browser = webdriver.Chrome(executable_path=r".\chromedriver.exe")
    browser.get(webaddy)

    #Search for element and put in variable
    elem = browser.find_element_by_css_selector('.post-title')
    prices = browser.find_element_by_css_selector('.price_inside_buybox')


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

#Price Compare
    print("Price comparator")
    if (priceText >= price_limit):
        print("Darn, wait a bit")

    if (priceText < price_limit):
        print("Price is lower ")
        send_mail()

def send_mail():
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.ehlo()

    #Your email and pass
    UMAIL = ""
    UPASS = ""
    
    server.login(UMAIL, UPASS)

    subject = 'Price Fell Down!'
    body = f'Check the Unreal link {webaddy}'

    msg = f"Subject: {subject}\n\n{body}"

    server.sendmail(
        UMAIL,
        msg
    )

    print("Email Sent with Price Drop")

    server.quit()


while(True):
    check_price()
    time.sleep(60 * 60 * 24)
#    time.sleep(60 * 60 * 24)
