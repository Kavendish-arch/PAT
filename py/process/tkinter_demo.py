import tkinter



MainForm = tkinter.Tk()
MainForm.iconbitmap('fom.ico')
MainForm.geometry('250x150')
MainForm.title("hello")
MainForm["background"] = 'LightSlateGray'
btn1 = tkinter.Button(MainForm, text="exit", fg="black")
btn1.pack()
MainForm.mainloop()
