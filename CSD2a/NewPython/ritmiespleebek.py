import simpleaudio as sa
import time

wave_obj = sa.WaveObject.from_wave_file("/home/daan/Documents/C++/CSD2/CSD2/CSD2a/python_basics/Samples/ClosedHH_1.wav")

#bpm calculation
bpm = float(input("what is the BPM: "))
BPM = ((60000 / bpm) / 2000)
print(BPM)
#amount of hits
impulseAmount = int(input("How many notes: "))
#initiate list
notes = []
while impulseAmount > 0:
    note = float(input("Note length: "))
    notes.append(note)
#    print(notes)
    impulseAmount-= 1
    if impulseAmount == 0:
        print(notes)
# calculate time to rhythmic divisions
for x in notes:
    play_obj = wave_obj.play()
    sleeptime = BPM * x
#    print(sleeptime)
    time.sleep(sleeptime)
