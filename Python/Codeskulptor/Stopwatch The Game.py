# template for "Stopwatch: The Game"
import simplegui
# define global variables
t =0
message = '0:00.0'
game_num = 0
game_win = 0
state = '0/0'

# define helper function format that converts time
# in tenths of seconds into formatted string A:BC.D
def format(t):
    global message
    second_last = str(t % 10)
    second_last2 = t % 100
    second_middle = str(second_last2 / 10)
    first2 = t / 100
    minute = str(first2 / 6)
    second_first = str(first2 % 6)
    message = minute + ':' + second_first + second_middle + '.' + second_last

def game_state():
    global state, game_num, game_win
    win = str(game_win)
    num = str(game_num)
    state = win + '/'+ num
    
# define event handlers for buttons; "Start", "Stop", "Reset"
def start():
    timer.start()

def stop():
    global game_num, game_win
    timer.stop()
    game_num += 1
    if (t % 10 == 0):
        game_win += 1
    game_state()
    
def reset():
    global t, game_num, game_win
    t=0
    game_num = 0
    game_win = 0
    timer.stop()
    format(t)
    game_state()
    
# define event handler for timer with 0.1 sec interval
def t_change():
    global t
    t += 1 
    format(t)

# define draw handler
def draw(canvas):
    canvas.draw_text(message, [100, 120], 36, 'blue')
    canvas.draw_text(state, [250,50], 18, 'red')
     
# create frame
frame = simplegui.create_frame("Stopwatch: The Game", 300, 200)

# register event handlers
button1 = frame.add_button('Start', start, 100)
button1 = frame.add_button('Stop', stop, 100)
button1 = frame.add_button('Reset', reset, 100)
frame.set_draw_handler(draw)
timer = simplegui.create_timer(100, t_change)

# start frame
frame.start()

# Please remember to review the grading rubric
