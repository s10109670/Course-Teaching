import tkinter as tk


class GUI:
    def __init__(self):
        num = 8
        win = tk.Tk()
        win.title('超級飲料手')
        win.geometry('{}x{}'.format(600, 600))
        win.resizable(0, 0)
        time = [0]
        info = tk.Label(win, text = '總等待時間: {} 分鐘'.format(sum(time)),
                        font = ('Consolas', 20),padx = 20, pady =20, justify = tk.LEFT)
        info.grid(row = 0)
        frames = [tk.Frame(win, width = 600, pady = 10, padx = 5) for i in range(num)]
        person = []
        for i in range(len(frames)):
            frames[i].grid(row = i+1, column = 0, sticky = 'w')
            person.append(tk.Label(frames[i], text = '客人{}'.format(i+1),
                                   font = ('Consolas', 20),justify = tk.LEFT))
            person[-1].pack(side = tk.LEFT)
        def a():
            frames[-1].destroy()
            frames.pop()
        btn = tk.Button(win, text = 'del', command=a)
        btn.grid(row = num+1, column = 0)
##        self.__start =  start_btn 
##        self.__restart()
        win.mainloop()

        
##
##    def __restart(self):
##        for i in range(self.h):
##            for j in range(self.w):
##                self.__btn_state[i][j] = 0                
##                for key in self.appearance[self.__btn_state[i][j]]:
##                    self.__btns[i][j][key] = self.appearance[self.__btn_state[i][j]][key]
##                    self.__btns[i][j]['state'] = 'normal'
####                self.__btns[i][j]['text'] = ''
####                self.__btns[i][j]['bg'] = '#46A3FF'
##    def step(self, a):
##        i, j = a
##        self.__btn_state[i][j] = (self.__btn_state[i][j]+1)%3
##        for key in self.appearance[self.__btn_state[i][j]]:
##            self.__btns[i][j][key] = self.appearance[self.__btn_state[i][j]][key]
##    
##    
##    def play(self):
##        self.__win.mainloop()

def main():
##    n = int(input())
    game = GUI()
    
if __name__ == '__main__':
    main()
