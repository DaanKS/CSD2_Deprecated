import simpleaudio as sa
import time

wave_obj = sa.WaveObject.from_wave_file("Samples/ClosedHH_1.wav")

# ask the user for the speed
play_times = int(input("Hoe veel nootjes? "))
# create a list upfront so it actually works ;)
note_seq = []
# a while loop to ask for user input
# asking for note durations and turning that into a list (sequence)
while play_times > 0:
     n = float(input("Noot waarde kies uit: 0.5 1.0 1.5 2.0 "))
     note_seq.append(n)
     play_times -=1

# print the list for confirmation - no confirmation needed
print(note_seq)
bpm = int(input("Snelheid? in bpm " ))


# een functie maken die de note_seq en BPM omzet naar tijd duraties
note_speed = 60.0 / bpm

play_times = len(note_seq)

while play_times > 0:
    note_number = 0
    l = note_seq.pop(note_number)
    step_duration = l * note_speed
    play_obj = wave_obj.play()
    time.sleep(step_duration)
    note_number += 1
    play_times -= 1
# tijd duraties keer de ingevoerde lijst om speel duraties uit te rekenen
