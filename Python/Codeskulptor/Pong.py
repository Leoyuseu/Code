# Implementation of classic arcade game Pong

import simplegui
import random

# initialize globals - pos and vel encode vertical info for paddles
WIDTH = 600
HEIGHT = 400       
BALL_RADIUS = 20
PAD_WIDTH = 8
PAD_HEIGHT = 80
HALF_PAD_WIDTH = PAD_WIDTH / 2
HALF_PAD_HEIGHT = PAD_HEIGHT / 2
LEFT = False
RIGHT = True

# initialize ball_pos and ball_vel for new bal in middle of table
ball_pos=[0,0]  
ball_vel = [0, 0]

paddle1_pos = [HALF_PAD_WIDTH,200]  
paddle2_pos = [WIDTH-HALF_PAD_WIDTH,200]  
paddle1_vel = 0  
paddle2_vel = 0  

score1 = 0
score2 = 0

# if direction is RIGHT, the ball's velocity is upper right, else upper left
def spawn_ball(direction):
    global ball_pos, ball_vel # these are vectors stored as lists
    ball_pos = [int(WIDTH/2), int(HEIGHT/2)]
    ball_vel = [random.randrange(120, 240),random.randrange(60, 180)] 
    if direction == LEFT:
        ball_vel[0]= -ball_vel[0]  


# define event handlers
def new_game():
    global paddle1_pos, paddle2_pos, paddle1_vel, paddle2_vel  # these are numbers
    global score1, score2  # these are ints
    score1 = 0
    score2 = 0
    spawn_ball(RIGHT)

def draw(c):
    global score1, score2, paddle1_pos, paddle2_pos, ball_pos, ball_vel
        
    # draw mid line and gutters
    c.draw_line([WIDTH / 2, 0],[WIDTH / 2, HEIGHT], 1, "White")
    c.draw_line([PAD_WIDTH, 0],[PAD_WIDTH, HEIGHT], 1, "White")
    c.draw_line([WIDTH - PAD_WIDTH, 0],[WIDTH - PAD_WIDTH, HEIGHT], 1, "White")
        
    # update ball
    if (ball_pos[1] <= BALL_RADIUS) or (ball_pos[1] >= HEIGHT-BALL_RADIUS):  
        ball_vel[1]= -ball_vel[1]  
        
    if ball_pos[0] <= BALL_RADIUS:  
        if paddle1_pos[1] <= ball_pos[1] <= paddle1_pos[1]+PAD_HEIGHT:  
            ball_vel[0] = -ball_vel[0]  
            ball_vel[0] = ball_vel[0]*1.1  
            ball_vel[1] = ball_vel[1]*1.1  
        else:  
            spawn_ball(LEFT)  
            score2 += 1  
    elif ball_pos[0] >= WIDTH-BALL_RADIUS:  
        if paddle2_pos[1] <= ball_pos[1] <= paddle2_pos[1]+PAD_HEIGHT:  
            ball_vel[0] = -ball_vel[0]  
            ball_vel[0] = ball_vel[0]*1.1  
            ball_vel[1] = ball_vel[1]*1.1  
        else:  
            spawn_ball(RIGHT)  
            score1 += 1  
              
    ball_pos[0]+= ball_vel[0]/60  
    ball_pos[1]+= ball_vel[1]/60          
    # draw ball
    c.draw_circle(ball_pos, 20, 1, "Red", "Yellow")  

    # update paddle's vertical position, keep paddle on the screen
    if 0 <= paddle1_pos[1] + paddle1_vel <= HEIGHT-PAD_HEIGHT:
        paddle1_pos[1] += paddle1_vel  
    if 0 <= paddle2_pos[1] + paddle2_vel <= HEIGHT-PAD_HEIGHT:
        paddle2_pos[1] += paddle2_vel
    # draw paddles
    c.draw_line(paddle1_pos,[paddle1_pos[0], paddle1_pos[1]+PAD_HEIGHT], PAD_WIDTH, "White")   
    c.draw_line(paddle2_pos,[paddle2_pos[0], paddle2_pos[1]+PAD_HEIGHT], PAD_WIDTH, "White")   
    # draw scores
    c.draw_text(str(score1)+":" +str(score2), (280, 200), 40, "White")     

def keydown(key):
    global paddle1_vel, paddle2_vel
    vel = 2  
    if key == simplegui.KEY_MAP['w']:  
        paddle1_vel = -vel  
    elif key == simplegui.KEY_MAP['s']:  
        paddle1_vel = vel  
    elif key == simplegui.KEY_MAP['up']:  
        paddle2_vel = -vel  
    elif key == simplegui.KEY_MAP['down']:  
        paddle2_vel = vel  
   
def keyup(key):
    global paddle1_vel, paddle2_vel
    if key == simplegui.KEY_MAP['w']:  
        paddle1_vel = 0  
    elif key == simplegui.KEY_MAP['s']:  
        paddle1_vel = 0
    elif key == simplegui.KEY_MAP['up']:  
        paddle2_vel = 0  
    elif key == simplegui.KEY_MAP['down']:  
        paddle2_vel = 0  


# create frame
frame = simplegui.create_frame("Pong", WIDTH, HEIGHT)
frame.set_draw_handler(draw)
frame.set_keydown_handler(keydown)
frame.set_keyup_handler(keyup)


# start frame
frame.start()
new_game()

