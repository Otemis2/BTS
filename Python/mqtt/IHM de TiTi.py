from tkinter import *
import paho.mqtt.client as mqtt

def publier(msg):
    
    broker_address="192.168.1.184" 
    #broker_address="iot.eclipse.org" #use external broker
    client = mqtt.Client("HUCK") #create new instance
    client.connect(broker_address) #connect to broker
    client.publish(msg)#publish
    
def souscrire(topic):

    client.subscribe(topic)

def on_message(client, userdata, message):
    print(topic+" dit : " ,str(message.payload.decode("utf-8")))



fen=Tk()

fen.geometry("600x400")

annonceSouscription=Label(height=2, width= 35, text="Application de messagerie (protocle MQTT)")
annonceSouscription.grid(row=0,column=1)

annonceSouscription=Label(height=2, width= 24, text="Souscription à un topic:")
annonceSouscription.grid(row=1,column=0)

infoSouscription=Label(height=1, width= 24, text="Saisir le nom du topic:")
infoSouscription.grid(row=2,column=0)

topic=StringVar()
lETopic=Entry(fen, textvariable=topic)
lETopic.grid(row=2,column=1)

bpSouscrire =Button(fen, text="Souscrire au topic", command= souscrire)
bpSouscrire.grid(row=2,column=2)

lInfoAbo=Label(height=1, width= 30, text="Abonnement(s) en cours au(x) topic(s): ")
lInfoAbo.grid(row=3,column=0)

lAbo=Label(height=1, width= 30, text="Aucun abonnement pour le moment")
lAbo.grid(row=3,column=1)

lInfoMsgRecu=Label(height=5, width= 24, text="Message reçu : ")
lInfoMsgRecu.grid(row=5,column=0)

client.on_message=on_message
lMsgRecu=Label(height=6, width= 24, text="Aucun message à afficher ...")
lMsgRecu.grid(row=5,column=1)

bpPublier=Button(fen, text="Publier un message", command=publier)
bpPublier.grid(row=8,column=0)

msg=StringVar()
lEMsg=Entry(fen, textvariable=msg)
lEMsg.grid(row=8,column=1)

fen.mainloop()
