import simpleaudio as sa

import os
os.path.join(".","Samples","ClosedHH_1.wav") # misschien handig

print ('Hello')

wave_obj = sa.WaveObject.from_wave_file("Samples/ClosedHH_1.wav")

# play_obj = wave_obj.play()
# play_obj.wait_done()

# user instructions
n = int(input("Hoe vaak? "))
print  ("playing" , n , "times")

# recursive function to play the n amount of times
def playsound(n):
    if n >= 1:
        play_obj = wave_obj.play()
        play_obj.wait_done()
        playsound(n-1)

    elif n == 0:
        play_obj.wait_done()
#    else:
#        play_obj = wave_obj.play()
#        playsound(n-1)
playsound(n)
