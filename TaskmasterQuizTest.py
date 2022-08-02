print('Welcome to Taskmaster Quiz')
answer=input('Are you ready to play the Taskmaster Quiz? (yes/no) :')
score=0
total_questions=3
 
if answer.lower()=='yes':
    answer=input('Question 1: Who won first round of Taskmaster?')
    if answer.lower()=='Jake':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')
 
 
    answer=input('Question 2: How many points do you get for winning a round in Taskmaster?? ')
    if answer.lower()=='5':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')
 
    answer=input('Question 3: What does the winner get at the end of the season?\n a) Bust\nc) Eyebrow\nc) Car')
    if answer.lower()=='bust':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')
 
print('Taskmaster Home quiz game, you attempted',score,"questions correctly!")
mark=(score/total_questions)*100
print('Marks obtained:',mark)
print('BYE!')
