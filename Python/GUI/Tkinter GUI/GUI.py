# -*- coding: utf-8 -*-
import Tkinter

root= Tkinter.Tk()    #生成主窗口
label = Tkinter.Label(root,text = "hello\npython",
                      width = 20,
                      height = 20,
                      justify = Tkinter.LEFT)  #生成标签,显示文本灬图片
label.pack()                                #将标签添加到root主窗口
button1 = Tkinter.Button(root,                         
                         anchor = Tkinter.E,
                         text = 'button1',
                         width = 40,
                         height = 5,
                         bg = 'red',
                         bd = 2,
                         font = 45,
                         state = Tkinter.DISABLED)  #生成button1
button1.pack()
button2 = Tkinter.Button(root, text = 'button2')  #生成button1
button2.pack(side = Tkinter.LEFT)
                         
entry1 = Tkinter.Entry(root,
                       bg = 'yellow',
                       selectforeground = 'red')
entry1.pack()

edit1 = Tkinter.Text(root)
edit1.pack()

menu = Tkinter.Menu(root)
submenu = Tkinter.Menu(menu, tearoff = 0)
submenu.add_command(label = 'open')
submenu.add_separator()
submenu.add_command(label = 'save')
menu.add_cascade(label = 'file', menu = submenu)

root.config(menu = menu)

root.mainloop()     
