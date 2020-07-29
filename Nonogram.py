import tkinter as tk
from tkinter import messagebox

class GUI:
    appearance = [{'bg':'#CCCCCC', 'text':''},
                     {'bg':'black', 'text':''},
                     {'bg':'#FFFFFF', 'text':'X', 'fg':'red'}]
    def __init__(self, row_data, col_data):
        w, h = len(col_data), len(row_data)
        win = tk.Tk()
        win.title('數織')
        win.geometry('{}x{}'.format(w*60+150, h*55+150))
        win.resizable(0, 0) 
##        start_btn = tk.Button(win, text = 'O',command = self.__restart, 
##                                   font = ('Arial', 20),bg = 'yellow')
##        start_btn.pack(padx = 0, pady =10)
        fr = tk.Frame(win)
        fr.pack(side = tk.BOTTOM, pady=10)
        board_btn = [[tk.Button(fr, command = lambda a=(i,j):self.step(a),
                                width = 3, height = 1, 
                                font = ('Arial', 20))
                      for j in range(w)]for i in range(h)]
        label_row = [tk.Label(fr, text = ' '.join(row_data[i]),
                              font = ('Consolas', 20),) for i in range(h)]
        label_col = [tk.Label(fr, text = '\n'.join(col_data[j]),
                              font = ('Consolas', 20),) for j in range(w)]
        for i in range(h):
            label_row[i].grid(row = i+1, column = 0, sticky='e')
            for j in range(w):
                board_btn[i][j].grid(row = i+1,column = j+1)
        for j in range(w):
            label_col[j].grid(row = 0, column = j+1, sticky='s')
        self.w = w
        self.h = h
        self.__win = win
        self.__btn_state = [[0]*w for i in range(h)]
        self.__btns = board_btn
##        self.__start = start_btn 
        self.__restart()
        
    def __restart(self):
        for i in range(self.h):
            for j in range(self.w):
                self.__btn_state[i][j] = 0                
                for key in self.appearance[self.__btn_state[i][j]]:
                    self.__btns[i][j][key] = self.appearance[self.__btn_state[i][j]][key]
                    self.__btns[i][j]['state'] = 'normal'
##                self.__btns[i][j]['text'] = ''
##                self.__btns[i][j]['bg'] = '#46A3FF'
    def step(self, a):
        i, j = a
        self.__btn_state[i][j] = (self.__btn_state[i][j]+1)%3
        for key in self.appearance[self.__btn_state[i][j]]:
            self.__btns[i][j][key] = self.appearance[self.__btn_state[i][j]][key]
    
    
    def play(self):
        self.__win.mainloop()

def main():
    n = int(input())
    row = [input().split() for i in range(n)]
    col = [input().split() for i in range(n)]
    game = GUI(row, col)
    game.play()
    
if __name__ == '__main__':
    main()
