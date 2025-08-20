# 03 - Odd or Even Number

This is a simple program that checks whether a number entered by the user is odd or even.

## Problem-Solving Step

1. **Read** a number from the user.  
2. **Calculate**: `Result = Number % 2`. 
3. **Check** the result:  
   - If `Result == 0` → **Print** `"The Number is Even"`.  
   - Otherwise → **Print** `"The Number is Odd"`.

## Flowchart of the Problem
_______
```mermaid
flowchart TD
    A((Start)) --> B[/Read Number/]
    B --> C[Result = Number % 2]
    C --> D{Result == 0?}
    D -->|Yes| E[Number is Even]
    D -->|No| F[Number is Odd]
    E --> G((End))
    F --> G((End))

 %% Colors
    style A fill:#4CAF50,stroke:#333,color:white
    style B fill:#B0BEC5,stroke:#333,color:white
    style C fill:#2196F3,stroke:#333,color:white
    style D fill:#F44336,stroke:#333,color:white
    style E fill:#FF9800,stroke:#333,color:white
    style F fill:#9C27B0,stroke:#333,color:white
    style G fill:#4CAF50,stroke:#333,color:white
```

## Flowchart of the code
_______

```mermaid
flowchart TD
    A((Start)) --> B[/Call Function ReadNumber/]
    B --> C[Call Function CheckNumberType]
    C --> D[\Call Function PrintNumberType\]
    D --> E((End))

 %% Colors
    style A fill:#4CAF50,stroke:#333,color:white
    style B fill:#B0BEC5,stroke:#333,color:white
    style C fill:#2196F3,stroke:#333,color:white
    style D fill:#BA68C8,stroke:#333,color:white
    style E fill:#F44336,stroke:#333,color:white
```

## Source Code

You can view or download the C++ solution here: [Odd or Even](odd-or-even.cpp)
