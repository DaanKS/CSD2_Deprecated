import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("/home/daan/Documents/C++/CSD2/CSD2/CSD2a/python_basics/Samples/ClosedHH_1.wav")
play_obj = wave_obj.play()
play_obj.wait_done()
