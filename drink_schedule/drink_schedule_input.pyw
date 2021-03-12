import tkinter as tk



class Drink_Serve:
    def __init__(self, c):
        c.sort(key = lambda x:x[1], reverse = True)
        s = []
        time = [0,0]
        while len(c) > 0 and c[-1][1] == time[0]:
            s.append(c.pop())
        wd = tk.Tk()
        wd.title('超級飲料手')
        wd.geometry('{}x{}'.format(600, 600))
        wd.resizable(0, 0)
        self.wd = wd
        self.c, self.s, self.time = c, s, time
        self.win = self.show()

        
        
    def show(self):
        c, s, time = self.c, self.s, self.time
        win = tk.Frame(self.wd, height = 600, width = 600)
        win.pack(side = tk.TOP, fill=None, expand=False)
        win.pack_propagate(0)
        info = tk.Label(win, text = '已經過了{}分, 總等待時間: {} 分鐘'.format(time[0], time[1]),
                        font = ('Consolas', 20),padx = 20, pady =20, justify = tk.LEFT)
        info.pack(side = tk.TOP)
        frames = [tk.Frame(win, borderwidth = 1, relief = tk.SUNKEN,
                           height = 50,width = 500, pady = 10, padx = 5) for i in range(len(s))]
        data = []
        for i in range(len(s)):
            frames[i].pack(side = tk.TOP, fill=None, expand=False)
            frames[i].pack_propagate(0)
            data.append([tk.Label(frames[i], text = s[i][0],
                                  font = ('Consolas', 20), justify = tk.LEFT),
                         tk.Label(frames[i], text = '已做{}/{}, 等了{}分'.format(s[i][3], s[i][2], s[i][4]),
                                  font = ('Consolas', 20), padx = 5, justify = tk.RIGHT),
                         tk.Button(frames[i], text = '製作', command = lambda b = i :self.a(b),
                                   font = ('Consolas', 14), padx = 10)])
            data[-1][0].pack(side = tk.LEFT)
            data[-1][2].pack(side = tk.RIGHT, padx = 20)
            data[-1][1].pack(side = tk.RIGHT)
        return win
    def a(self, i):
        c, s, time = self.c, self.s, self.time
        time[0] += 1
        time[1] += len(s)
        for d in s:
            d[4] += 1
        s[i][3] += 1
        if s[i][3] == s[i][2]:
            s.pop(i)
        while len(c) > 0 and c[-1][1] == time[0]:
            s.append(c.pop())
        self.win.destroy()
        self.win = self.show()
        
        
##        self.__start =  start_btn 
##        self.__restart()

        
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
    def play(self):
        self.wd.mainloop()

def main():
    n = int(input())
    ##customer = [name, coming_time, total_num, done_num, waiting_time]
    customers = [input().split()+[0,0] for i in range(n)]
    for c in customers:
        c[1] = int(c[1])
        c[2] = int(c[2])
    game = Drink_Serve(customers)
    print('begin')
    game.play()
    
if __name__ == '__main__':
    main()
