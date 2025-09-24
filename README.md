# Lexical Analyzer for Numeric Types

## About This Project

This project is an assignment for the **Formal Languages and Automata Theory** course. It features a lexical analyzer, implemented in C, designed to parse and classify different formats of numeric strings.

The core of the program is a **Deterministic Finite Automaton (DFA)** that identifies integers, signed integers, floating-point numbers, and signed floating-point numbers. The state transitions of the automaton are implemented directly using `goto` labels for clarity and to closely mirror the state transition diagram.

## Recognized Tokens

The analyzer processes input strings and classifies them into one of the following categories:

  * `<INTEIRO>`: An unsigned integer (e.g., `21`, `021`).
  * `<INTEIRO COM SINAL>`: A signed integer (e.g., `-21`, `+50`).
  * `<P.FLUTUANTE>`: An unsigned floating-point number (e.g., `2,1`, `0005,5678`).
  * `<P.FLUTUANTE COM SINAL>`: A signed floating-point number (e.g., `-2,1`, `+0,012`).
  * `<REJEITADO>`: Any string that does not match the defined numeric patterns (e.g., `2.1`, `+0,34a`).

**Note:** This automaton uses a comma (`,`) as the decimal separator, following some regional conventions. Inputs with a period (`.`) are rejected.

## How to Run

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/PineMi/poc_state_machine_numbers.git
    cd poc_state_machine_numbers
    ```

2.  **Compile the code:**
    You can use any standard C compiler, such as GCC.

    ```bash
    gcc main.c -o scanner
    ```

3.  **Execute the program:**
    The `main` function contains a predefined list of test cases. Simply run the compiled executable to see the output.

    ```bash
    ./scanner
    ```
4. **Test your Samples:**
   If you wish to try any number, just change the array in main.c, compile and run it again!
   Happy Coding ;)

## JFlap Applied Automata Model
<img width="923" height="470" alt="image" src="https://github.com/user-attachments/assets/e390b6f6-155e-49e9-b29b-a78d71be1424" />
<img width="1280" height="574" alt="image" src="https://github.com/user-attachments/assets/0eab9e5d-d89f-4bc8-bc69-1afc8821f381" />

## Authors

  * **Bruno Germanetti Ramalho**
  * **Miguel Piñeiro Coratolo Simões**
  * **Thais Ferreira Canguçu**
