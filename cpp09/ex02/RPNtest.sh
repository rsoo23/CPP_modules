#!/bin/bash

# Run make to compile the code
make

# Check if make was successful
if [ $? -eq 0 ]; then
    # Provide the valid and invalid RPN test cases
    valid_test_cases=(
        "3 4 +"
        "5 6 *"
        "8 2 /"
        "7 2 -"
        "1 2 + 3 *"
        "4 5 + 6 *"
        "4 2 / 3 *"
        "7 3 / 2 *"
        "9 2 - 5 *"
        "6 3 / 2 +"
        "8 9 * 9 - 9 - 9 - 4 - 1 +"
        "7 7 * 7 -"
        "1 2 * 2 / 2 * 2 4 - +"
        "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
        "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
    )
    invalid_test_cases=(
        "56*"
        "* 5 6"
        "1.8 1.9 +"
        " 1 9 +"
        "1 9+"
        "1 9 +  "
        "10 9 +"
        "7 2 - ksdjflksjdf"
        "7 2"
        "sf sdf"
        "2s 4d"
        "3 4 + +"
        "5 6 * +"
        "8 2 / *"
        "1 2 + 3 * /"
        "4 5 + 6 * -"
        "10 2 / 3 * +"
        "9 2 - 5 * +"
        "6 3 / 2 + *"
    )
    # Run the executable with valid test cases
    echo "Running RPN with valid test cases:"
    for valid_case in "${valid_test_cases[@]}"; do
        echo "Test Case: $valid_case =>"
        ./RPN "$valid_case"
        echo ""
    done

    echo "_________________________________________________________________________________________________________________"
    # Run the executable with invalid test cases
    echo "Running RPN with invalid test cases:"
    for invalid_case in "${invalid_test_cases[@]}"; do
        echo "Test Case: $invalid_case =>"
        ./RPN "$invalid_case"
        echo ""
    done

else
    echo "Compilation failed. Please check your code."
fi
