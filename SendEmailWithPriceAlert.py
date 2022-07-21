##Basic function to send email. Recommended you uses a service pass if storing in file. 


def send_mail():
    #Send email to account if it is below price.
    UMAIL = ""
    UPASS = ""

    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.ehlo()

    server.login(UMAIL, UPASS)

    #Subject - Change as needed
    subject = 'Price Fell Down!'

    #Body of email
    body = f'Check the Amazon link {webaddy}'

    msg = f"Subject: {subject}\n\n{body}"

    server.sendmail(
        UMAIL,
        msg
    )

    print("Email Sent with Price Drop")

    server.quit()
