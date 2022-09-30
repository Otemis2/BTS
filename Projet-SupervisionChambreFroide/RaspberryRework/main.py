from Cmqtt import CMqtt
from config import *
import time

time.sleep(5)

monMQTT = CMqtt()#Instancie la classe CMqtt
clientMqtt = monMQTT.getClient()#Récupère le client de la classe mqtt
clientMqtt.on_connect = monMQTT.connecter #Souscription des topics
clientMqtt.on_message = monMQTT.receptionnerMessageMQTT #Réceptionnent les messages
clientMqtt.loop_forever()#Boucle infini
