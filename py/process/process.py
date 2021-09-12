import _thread
import threading
from datetime import datetime
from time import *

tickets = [
    ['2018-4-7 8:00', '北京', '沈阳', 10, 120],
    ['2018-4-7 8:00', '北京', '沈阳', 10, 120],
    ['2018-4-7 8:00', '北京', '沈阳', 10, 120],
    ['2018-4-7 8:00', '北京', '沈阳', 10, 120],
    ['2018-4-7 8:00', '北京', '沈阳', 10, 120],
    ['2018-4-7 8:00', '北京', '沈阳', 10, 120],
]


def buy_ticket(name, nums, data1, start_station):
    i = 0
    sleep(1)
    for get_record in tickets:
        if get_record[0] == data1 and get_record[1] == start_station:
            if get_record[3] >= nums:
                tickets[i][3] = get_record[3] - nums
                print(name, 'buy ticket succeed!')
                return
            else:
                print('not enough tickets')
                return -1
        i += 1
    print('today ticket is sale out')
    return -1


class MyThread(threading.Thread):
    def __init__(self, target, args):
        threading.Thread.__init__(self)
        self.target = target
        self.args = args

    def run(self) -> None:
        self.target(*self.args)
        return super().run()


if __name__ == '__main__':


    print("start date: ", datetime.now())
    t1 = threading.Thread(target=buy_ticket, args=('张三', 2, '2018-4-7 8:00','北京'))
    t2 = threading.Thread(target=buy_ticket, args=('张三', 2, '2018-4-7 8:00','上海'))
    t3 = threading.Thread(target=buy_ticket, args=('张三', 2, '2018-4-7 8:00','北京'))
    t4 = threading.Thread(target=buy_ticket, args=('张三', 2, '2019-4-7 8:00','北京'))
    t5 = MyThread(target=buy_ticket, args=('张三', 2, '2019-4-7 8:00','北京'))
    
    t = [t1, t2, t3, t4, t5]
    for i in t:
        i.start()

    for i in t:
        i.join()

    print('结束时间: ', datetime.now())
    print('-'*10)

def func():
    print("hello")
print (threading.active_count())
print (threading.current_thread())
print (threading.get_ident())
print (threading.enumerate())
print (threading.main_thread())
print (threading.settrace(func))
print (threading.setprofile(func))
print (threading.stack_size())

thr1 = threading.Thread(target=func, name="hello world", daemon=True)
thr1.start()
thr1.join
