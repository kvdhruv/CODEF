0 6 -2 1 -4 5  -> 0 6 2 -1 -4 5
0 6  4 5  1 6  -> 0 6 8  7  3 8 => prefix sums. -> contribtion flipped. -1 -> +1, delta = +2
                       4 - 5 -> 8 - 7 difference flipped.
6 -8 3 -5 9    -> 6 -4 -3 -3 9 -> sign of diff changes in range -> obv. 
                                  borders =? changes to to their abs diff ? 
                                  leading no where. 
prefix sums ? i want to maximise pref[n - 1]. -> total sum

can use 1 2
range updates. -> xor of i % range is constant. 