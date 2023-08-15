BITNINE
-------

This code for bitnine intenship

## PREQUISITES
- Docker
- Docker compose

## STEPS TO RUN
- Clone the project
  ```ssh
    git clone git@github.com:SofyanMahmoud0000/internship.git
  ```

- Navigate the project root directory
  ```ssh
    cd internship
  ```
- To run question_1, hit the command
  ```ssh
    sudo docker compose run question_1 sh -c "g++ -w /app/question_1.cpp -o /app/a.out && /app/a.out" 
  ```

- To run question_2, hit the command
  ```ssh
    sudo docker compose run question_2 sh -c "gcc -w /app/question_2.c -o /app/a.out && /app/a.out" 
  ```

## QUESTION 2 COMPARISON


In question 2 I have used 3 methods
- `normal recursion` which is
  - O(2^n) Time complexity
  - O(n) Space complexity
  - And when you run the code you will notice that this method are very sloooow cause the time complexity is exponential

- `Top-Down Dynamic programming` using `Momization` which is
  - O(n) Time complexity
  - O(n) Space complexity - cause of the momization and the call stack

- `Bottom-up Dynamic programming` using `Iteration` which is
  - O(n) Time complexity
  - O(n) Space complexity
  - Note: We can enhance the space complexity to be O(1) if we used just 2 variables represents the f(n-3) and f(n-2)


  