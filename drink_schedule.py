import tkinter as tk

class Drink_Serve:
    def __init__(self, c):
        c.sort(key = lambda x:x[1], reverse = True)
        s = []
        finish = []
        time = [0,0]
        while len(c) > 0 and c[-1][1] == time[0]:
            s.append(c.pop())
        wd = tk.Tk()
        wd.title('超級飲料手')
        wd.geometry('{}x{}'.format(600, 600))
        wd.resizable(0, 0)
        self.wd = wd
        self.c, self.s, self.time, self.f = c, s, time, finish
        self.win = self.show()
        
    def show(self):
        c, s, time, finish = self.c, self.s, self.time, self.f
        win = tk.Frame(self.wd, height = 600, width = 600)
        win.pack(side = tk.TOP, fill=None, expand=False)
        win.pack_propagate(0)
        info = tk.Label(win, text = '已經過了{}分, 總等待時間: {} 分鐘'.format(time[0], time[1]),
                        font = ('Consolas', 20),padx = 20, pady =20, justify = tk.LEFT)
        info.pack(side = tk.TOP)
        frames = [tk.Frame(win, borderwidth = 1, relief = tk.SUNKEN,
                           height = 50,width = 500, pady = 10, padx = 5) for i in range(len(s))]
        frames_end = [tk.Frame(win, borderwidth = 1, relief = tk.SUNKEN,
                           height = 50,width = 500, pady = 10, padx = 5) for i in range(len(finish))]
        data = []
        data_end = []
        for i in range(len(s)):
            frames[i].pack(side = tk.TOP, fill=None, expand=False)
            frames[i].pack_propagate(0)
            data.append([tk.Label(frames[i], text = s[i][0],
                                  font = ('Consolas', 20), justify = tk.LEFT),
                         tk.Label(frames[i], text = '已做{}/{}, 等了{}分'.format(s[i][3], s[i][2], s[i][4]),
                                  font = ('Consolas', 20), padx = 5, justify = tk.RIGHT),
                         tk.Button(frames[i], text = '製作', command = lambda idx = i :self.make(idx),
                                   font = ('Consolas', 14), padx = 10)])
            data[-1][0].pack(side = tk.LEFT)
            data[-1][2].pack(side = tk.RIGHT, padx = 20)
            data[-1][1].pack(side = tk.RIGHT)
        for i in range(len(finish)):
            frames_end[i].pack(side = tk.BOTTOM, fill=None, expand=False)
            frames_end[i].pack_propagate(0)
            data_end.append([tk.Label(frames_end[i], text = finish[i][0],
                                  font = ('Consolas', 20), justify = tk.LEFT),
                         tk.Label(frames_end[i], text = '已做{}/{}, 等了{}分'.format(finish[i][3], finish[i][2], finish[i][4]),
                                  font = ('Consolas', 20), padx = 5, justify = tk.RIGHT)])
            data_end[-1][0].pack(side = tk.LEFT)
            data_end[-1][1].pack(side = tk.RIGHT)
        restart_btn = tk.Button(win, text = '重新開始', command = self.restart,
                            font = ('Consolas', 14), padx = 10)
        restart_btn.pack(side = tk.BOTTOM, pady=20)
        return win
    
    def restart(self):
        self.c = self.c + self.s + self.f
        for i in self.c:
            i[-1], i[-2] = 0, 0
        self.c.sort(key = lambda x:x[1], reverse = True)
        self.s = []
        self.f = []
        self.time = [0,0]
        while len(self.c) > 0 and self.c[-1][1] == self.time[0]:
            self.s.append(self.c.pop())
        self.win.destroy()
        self.win = self.show()

    def make(self, i):
        c, s, time = self.c, self.s, self.time
        time[0] += 1
        time[1] += len(s)-1
        for p in range(len(s)):
            if p != i:
                s[p][4] += 1
        s[i][3] += 1
        if s[i][3] == s[i][2]:
            self.f.append(s.pop(i))
        while len(c) > 0 and c[-1][1] == time[0]:
            s.append(c.pop())
        self.win.destroy()
        self.win = self.show()
	
    def play(self):
        self.wd.mainloop()



    
if __name__ == '__main__':
    #n = int(input())
    ##customer = [name, coming_time, total_num, done_num, waiting_time]
    customers = [['Bob', 0, 2, 0, 0],
                 ['Paul', 0, 10, 0, 0],
                 ['Judy', 5, 1, 0, 0],
                 ['Amy', 2, 5, 0, 0],
                 ['Maggie', 1, 2, 0, 0],
                 ['Show', 1, 3, 0, 0]]
    for c in customers:
        c[1], c[2] = int(c[1]), int(c[2])
    game = Drink_Serve(customers)
    game.play()
