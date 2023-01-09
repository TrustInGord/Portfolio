#This checks a craigslist website for the newest post. It writes the results to a file for later comparing. 
#This also sends an email to you if there is a difference.
#You should run this using Cron or Windows Secheduler once a day, or whenever needed.
#I recommend using a service password for sending an email.

import requests
from bs4 import BeautifulSoup
import smtplib

URL = "https://vancouver.craigslist.org/search/sof"
page = requests.get(URL)

soup = BeautifulSoup(page.content, 'html.parser')

results = soup.find(id='sortable-results')

newest_post = results.find_all('p', class_='result-info')[0]

title = newest_post.find('a', class_='result-title hdrlnk').text

# Read the contents of the previous newest post from the file
with open('last_newest_post.txt', 'r') as file:
    last_newest_post = file.read()

# Check if the newest post is different from the previous newest post
if title != last_newest_post:
    # Write the new newest post to the file
    with open('last_newest_post.txt', 'w') as file:
        file.write(title)

    # Send an email with the new newest post
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login("your-email@example.com", "your-password")

    message = "There is a new post on Craigslist: " + title
    server.sendmail("from-email@example.com", "to-email@example.com", message)
    server.quit()
