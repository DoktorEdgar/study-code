# Lab 5: Drone Test Bench & Data Diagnostics Toolkit

This lab focuses on **generic programming in C++** using templates, STL containers, iterators, and STL algorithms.

You will practice the following concepts:

- function templates
- multiple template parameters
- non-type template parameters
- template specialization
- STL containers
- iterators
- STL algorithms

Core idea: **write algorithms once and reuse them for many types**.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

In this lab, you will build parts of a **drone test bench software**.

Modern drones continuously generate data such as:
- sensor values (temperature, vibration, voltage)
- system states (active / inactive)
- configuration parameters

Your task is to build a **generic data processing toolkit** that can handle different data types efficiently.

## Section I: First Steps with Generic Functions

In this section, you implement **basic reusable tools** used in a drone test environment.
For that, you provide various generic functions to process the corresponding data.

### 🟢 Task 1: Emergency Payload Switch

During testing, payload parameters must sometimes be swapped quickly (e.g. switching between calibration values).

Write a **generic function** that swaps two values.

#### Requirements

- The function must work for at least:
  - `int`
  - `double`
  - `std::string`
- Use references so that the original values are actually changed
- Print the values before and after the swap
- Briefly describe in a code comment why a template is better here than writing three separate functions

---

### 🟢 Task 2: Sensor Frame Printer

A drone continuously receives **sensor frames** (small arrays of values).
Write a **generic function** that prints all elements of such a frame.

#### Requirements

- The function shall take:
  - an array
  - its size
- Output format example:
  - `[12, 15, 18, 21]`
- Test with:
  - integer array
  - double array
  - character array

---

### 🟢 Task 3: Weakest Signal Detector

To detect signal issues, the system must identify the **weakest measurement** in a frame.

Write a **generic function** that returns the smallest value in a frame.

#### Requirements

- Work for:
  - `int`
  - `double`
- Do not use STL algorithms

---

### 🟢 Task 4: Telemetry Tag Composer

Drone data is often labeled with metadata (e.g. sensor name + priority).

Write a **generic function with two type parameters** to print such pairs.

#### Requirements

- Accept two values of different types
- Output example:
  - `Channel: motor_temp | Priority: 2`

---

### 🟢 Task 5: Fixed-Size Packet Buffer

In Section I, you implemented a function that prints arrays using a size parameter.

In embedded drone systems, sensor frames often have a fixed size known at compile time.
This means:
- the size is part of the type (e.g. `int[4]`)
- it does not need to be passed as a function argument

In this task, you will **improve your existing functions** to support this concept.

#### Requirements

- Adapt your existing array-based functions so that:
  - the size is NOT passed as a parameter anymore
  - the function automatically determines the size
- Apply this idea to:
  - your print function (from Task 2)
  - your minimum function (from Task 3)

#### Test your solution with:

- an integer array of size 4
- a double array of size 6

#### Questions

Write the answers as comments:

- Why is the size no longer needed as a parameter?
- What advantage does this have compared to the previous version?

#### Important

- Do NOT create a class or container
- Work directly with arrays
- Reuse and adapt your previous functions instead of rewriting everything

---

## 🟡 Section II: Flight Recorder Data Analysis

The drone stores raw measurement data during test flights.

You now process this data using **STL containers and algorithms**.

---

### Task 6: Sort and Inspect Recorded Samples

A flight recorder captured the following data:

`42, 17, 42, 5, 99, 17, 63, 12`

#### Requirements

- Store the data in a `std::vector`
- Print the original data
- Sort the data using a STL algorithm
- Print the sorted data
- Search for value `63`
- Output whether it exists

#### Note

- Add this task to your existing `main()` function 
- Organize your code into logical sections using comments

---

### Task 7: Noise Cleanup Pipeline

Sensor errors sometimes produce invalid values (`-1`).

Recorded data:

`7, -1, 13, -1, 21, 21, 8, -1, 8`

#### Requirements

- Replace all `-1` with `0`
- Count occurrences of value `8`
- Reverse the dataset
- Print results after each step
- Use STL algorithms

#### Note

- Add this task to your existing `main()` function 
- Organize your code into logical sections using comments

---

## 🟡 Section IV: Iterator-Based Processing

To understand how STL works internally, you now operate directly on iterators.

---

### Task 8: Manual Iterator Walk

#### Requirements

- Create a `std::vector<int>`
- Traverse using an explicit iterator
- Do NOT use range-based loops
- Print all elements

#### Questions

Answer as comments:

- What does `*it` do?
- What does `++it` do?

#### Context

STL algorithms internally use iterators — understanding them is essential.

---

## 🔴 Section V: Drone Mission Analyzer (Integration)

Now you combine everything into a **complete analysis tool**.

---

### Task 9: Build a Generic Analysis Toolkit

The drone test bench must evaluate recorded data automatically.

---

### Part A: Generic Analysis

Implement generic functions to compute:

- sum of values
- maximum value
- average value

#### Requirements

- Use `std::vector`
- Use STL algorithms where appropriate

---

### Part B: Special Case for System States

Drone logs may contain boolean values:

- `true` → system active
- `false` → system inactive

Implement a **template specialization** for one function.

#### Requirement

Return:

`true` if more than half of the values are true, otherwise false.

#### Context

Boolean data represents states, not numeric values — it must be handled differently.

---

### Part C: Integration Program

Build a program that:

1. Processes fixed sensor frames
2. Stores data in vectors
3. Cleans and analyzes recorded data
4. Applies your generic analysis functions
5. Handles boolean system states correctly

#### Output

For each dataset:

- raw data
- processed data
- computed results

---

## Reflection Questions

1. Why are templates useful in drone software?
2. Why do STL algorithms not depend on container type?
3. Why do some algorithms not work with all containers?
4. When is template specialization useful?
5. What disadvantages did you observe?

---

## Learning Outcomes

- write generic functions
- understand templates and specialization
- use STL containers and algorithms
- work with iterators
- build a small real-world inspired data processing system