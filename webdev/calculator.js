function* calculator(initialValue) {
    if (typeof initialValue !== "number") {
        throw new Error("Initial value must be a number");
    }

    let result = initialValue;

    while (true) {
        const input = yield result;

        if ( !input || typeof input.operation !== "string" || typeof input.value !== "number") {
            console.log("Invalid input");
            continue;
        }

        switch (input.operation) {
            case "add":
                result += input.value;
                break;

            case "subtract":
                result -= input.value;
                break;

            case "multiply":
                result *= input.value;
                break;

            case "divide":
                if (input.value === 0) {
                    console.log("Cannot divide by zero");
                    continue;
                }

                result /= input.value;
                break;

            default:
                console.log("Invalid operation");
        }
    }
}

const calc = calculator(50);

calc.next();

console.log(calc.next({ operation: "add", value: 30 }).value);

console.log(calc.next({ operation: "multiply", value: 2 }).value);

console.log(calc.next({ operation: "add", value: "30" }).value);

console.log(calc.next({ operation: "multiply", value: 0 }).value);