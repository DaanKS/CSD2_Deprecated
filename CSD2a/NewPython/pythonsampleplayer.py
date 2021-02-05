import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("/home/daan/Documents/C++/CSD2/CSD2/CSD2a/python_basics/Samples/ClosedHH_1.wav")


amount = int(input("how many to play here for: "))

while amount > 0:
    play_obj = wave_obj.play()
    play_obj.wait_done()
    amount-= 1
