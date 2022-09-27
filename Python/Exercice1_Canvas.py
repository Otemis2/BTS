from tkinter import*

#Fonctions et procédures

#Programe principal

frn=Tk()

can=Canvas(height=500,width=500)

can.pack()

can.config(bd = 2 ,bg = "cyan")

objet = can.create_line(250,0,250,500,fill="black",width = 4)
objet0 = can.create_line(0,250,500,250,fill="black",width = 4)
objet1 = can.create_rectangle(25,25,225,225,fill="orange",outline="green")
objet2 = can.create_oval(275,25,475,225,fill="yellow",outline="green",width = 2)
objet3 = can.create_text(375,375,text="Bravo",fill = "magenta",font=("Courier",25))
photo=PhotoImage(file='animal.gif')
can.create_image(125,375,image=photo)
