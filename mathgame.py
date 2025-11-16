from random import randint


import time



total_correct   = 0



total_incorrect = 0




total_skipped   = 0




print('\n' + 'Welcome to the math game version 0.1' + '\n' +




        '\n' + 'Entering the letter q as the answer will stop/terminate' +




        ' the program.' + '\n' +




        '\n' + 'Enjoy and have fun!' + '\n\n')




input('Press the Enter/Return key whenever you are ready to start.')



is_running = True



time_start = time.time()



time_end = time.time()




while is_running:



    first_number = randint(1, 12)



    second_number = randint(1, 12)



    the_sum = first_number + second_number



    print ( '\n' + str(first_number) + ' + ' + str(second_number) + ' = ?')



    the_answer = input('\n' + 'The answer is? ')




    if the_answer.isdigit():



        if int(the_answer) == the_sum:



            total_correct = total_correct + 1


            print('\n' + 'Correct!')




        else:



            total_incorrect = total_incorrect + 1


            print('\n' + 'Not correct!')



    else:




        if len(the_answer) < 1:


            total_skipped = total_skipped + 1



            print('\n' + 'No answer.. skipping...')



            continue





        if the_answer[0] == 'q':




            is_running = False





            time_end = time.time()





        else:




            print ('\n' + '[' + the_answer + ']' +



                ' is not a number, neither a valid command, ' +



                ' thus is not a valid answer.')






print ('\n' + 'Correct(s): ' + str(total_correct) +
        '    ' + 'Incorrect(s): ' + str(total_incorrect) +
        '    ' + 'Skipped: ' + str(total_skipped) +
        '    ' + 'Took ' + str(time_end - time_start) + ' seconds'
        '\n\n' + 'Goodbye!' + '\n' )




input('(Press Enter/Return to quit)')