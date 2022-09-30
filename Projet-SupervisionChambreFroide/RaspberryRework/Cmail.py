##encodage: utf-8
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import config

class CMail :

    """
    Documentation de la classe CMail :
    Cette classe permet l'envois d'un mail d'Alerte.
    Elle est composée de 3 méthodes :
    setMessage(nomChambre,codeAlerte) un muttateur
    setTo(destinataire) un mutateur
    envoyerMail() une méthode 
    
    Classe utiliser : 
    email.mime
    smtplib
    Documentation source :
    https://docs.python.org/3/library/email.mime.html
    https://docs.python.org/3/library/smtplib.html
    """
    #Initialisateur avec paramètre email et mot de passe de l'email
    def __init__(self,monEmail,mdpMail):
        """
        Méthode d'initialisation de la classe CMail
        Nécessitant deux paramètres :
        - l'email de l'expéditeur en chaîne de caractères
        - le mot de passe de l'expéditeur en chaîne de caractères
        
        Exemple d'appel : monEmail = CMail(toto@gmail.com,azerty88)
        """
        self.From = monEmail #Email de l'expéditeur
        self.mdpMail = mdpMail #Mot de passe de l'expéditeur
    
    def setMessage(self,nomChambre,codeAlerte):
        """
        Méthode permettant la préparation du message de l'email en fonction du code de l'alerte,
        Et précisant le nom de la chambre. 
        Nécessitant deux paramètres :
        - le nom de la chambre en chaîne de caractères
        - le code de l'alerte en entier
        
        Exemple d'appel : monEmail.setMessage(chambre1,1)
        """
        messageDebut ="Alerte la chambre nommé \""+str(nomChambre)+"\" a atteint un état critique.\n"#Premier paragraphe du mail qui précise le nom de la chambre
        messageFin = config.mailFin #Dernier paragraphe du mail.
        messageComplement = "" #Paragraphe qui change en fonction du code (type) de l'alerte.
        #print(codeAlerte)
        if codeAlerte == "1": #Si l'alerte concerne la porte
            messageComplement = config.mailPorte
        if codeAlerte == "2": #Si l'alerte concerne la température
            messageComplement = config.mailTemp
        messageComplet = messageDebut+messageComplement+messageFin #Assemblage du message
        self.message = messageComplet
        
    def setTo(self,destinataire):
        """
        Méthode permettant de modifier l'attribut to pour envoyer au destinataire le mail
        Nécessitant un paramètre :
        - le destinataire en chaîne de caractères
        
        Exemple d'appel : monEmail.setTo(chefDeService@hotmail.fr)
        """
        self.to = destinataire
        
    def envoyerMail(self):
        """
        Méthode permettant d'envoyer le mail d'alerte au destinataire
        Nécessitant aucun paramètre
        Exemple d'appel : monEmail.envoyerMail()
        """
        msg = MIMEMultipart()#Instanciation de la classe MIMEMultipart
        msg['From'] = self.From #Expéditeur
        msg['To'] = self.to #Destinataire
        msg['Subject'] = config.sujetMail #Objet du mail
        msg.attach(MIMEText(self.message)) #Permet convertir l'html
        mailserver = smtplib.SMTP(config.mailSMTP, config.portSMTP)#Connexion au serveur SMTP
        mailserver.ehlo()#Identification auprès d'un serveur ESMTP à l'aide d'EHLO.
        mailserver.starttls()#Passe la connexion SMTP en mode TLS (Transport Layer Security).
        #Toutes les commandes SMTP qui suivent seront cryptées. 
        mailserver.login(msg['From'], self.mdpMail)#Connexion à la boite de messagerie 
        mailserver.sendmail(msg['From'], msg['To'].split(","), msg.as_string())#Envois le mail
        mailserver.quit()#Termine la session SMTP et ce déconnecte. 
    
