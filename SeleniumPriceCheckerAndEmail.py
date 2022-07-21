#This is a simple price checking software designed on Amazon
#It uses Selenium to open a page and find out the price of an object.
#If it is on sale then it will email you using a service password for your email (or your real one if you don't want to do that)

from selenium import webdriver
import smtplib
import time


#Change web addres to which website you wish to price check
webaddy = "https://www.amazon.ca/Lucky-Iron-Fish-cooking-Standard/dp/B01LX5S5FP"

#Browser driver
wdrive = ""


def check_price():

    #Open Browser
    browser = webdriver.Chrome(executable_path=r".\chromedriver.exe")
    browser.get(webaddy)

    #Search for element and put in variable. Change as needed for website. This is designed for Amazon, but can be modified easily.
    search_field = browser.find_element_by_css_selector('#price_inside_buybox')

    elem = browser.find_element_by_css_selector("#price_inside_buybox")

    #browser.find_element_by_css_selector(body > div.main > div:nth-child(1) > div:nth-child(2) > a)

    #Test Variable to see if we got anything.
    print("Variable Phase")
    print(elem)

    print("Transfer to meow")
    meow = elem.text
    print(meow)

    print("\nMeow Stripped")
    x = meow.strip("CDN$ ")
    print(x)

    print("Price comparator")
    if (x >= '55.00'):
        print("Darn, wait a bit")

    if (x < '55.00'):
        print("Price is lower ")
        send_mail()

    browser.quit()

def send_mail():
    #Send email to account if it is below price.
    UMAIL = ""
    UPASS = ""

    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.ehlo()

    server.login(UMAIL, UPASS)

    subject = 'Price Fell Down!'
    body = f'Check the Amazon link {webaddy}'

    msg = f"Subject: {subject}\n\n{body}"

    server.sendmail(
        UMAIL,
        msg
    )

    print("Email Sent with Price Drop")

    server.quit()


while(True):
    #Timeline on how often to check for price updates
    check_price()
    time.sleep(60 * 60 * 24)
