from email.utils import formataddr
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.application import MIMEApplication
from email.mime.multipart import MIMEMultipart
import smtplib
import os

smtp = smtplib.SMTP('smtp.gmail.com', 587)
smtp.ehlo()
smtp.starttls()
smtp.login('my email removed for security', 'my password removed for security')

email_list = open('email_list.txt', 'r')
emails = [line.rstrip() for line in email_list]
print(emails)

emailSubject = input('Enter the email subject line here: ')
emailContent = input('Enter the email HTML here: ')

footer = '''<div>
        <br></br><hr><br></br>
        <h4 style="color:#ee2839;">Know an Ex!t fan who's feeling left out?</h4>
        <p style="color:black;">Send them <a href = 'actual form removed for security'>this link</a> to add themself to the mailing list!</p> 
        <br></br>
        
        <h4 style="color:#ee2839;">Contact Us</h4>
        <p style="color:black;"><a href = 'https://www.instagram.com/exitplayers/?hl=en'>Instagram</a></p>
        <p style="color:black;"><a href = 'mailto:directors@exitplayers.com'>Email</a></p>
        <p style="color:black;"><a href = 'http://www.exitplayers.com'>Website</a></p>
        <br></br>
        <img src="https://www.exitplayers.com/images/logos/yale_exit_players_cropped.jpg" alt="Ex!t Logo" width = "200px" height = "auto">
        <br></br>

        <p style="color:black;">Click <a href = 'actual form removed for security'>here</a> to be removed from the mailing list</p>
    </div>'''

htmlContent = emailContent + footer

msg = MIMEMultipart()
msg['Subject'] = emailSubject
msg['From'] = formataddr(('Yale Ex!t Players', 'my email removed for security'))
msg.attach(MIMEText(htmlContent, 'html'))

to = emails
smtp.sendmail(from_addr="my email removed for security",
              to_addrs=to, msg=msg.as_string())
smtp.quit()

print('\n\n\nSent!')
end = input('press enter to exit ')