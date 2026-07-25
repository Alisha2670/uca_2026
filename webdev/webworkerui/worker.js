self.onmessage = async function () {

    try {
        const response = await fetch("https://dummyjson.com/users");
        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }
        const data = await response.json();
        if (!data.users || data.users.length === 0) {
            self.postMessage([]);
            return;
        }
        const result = data.users.map(user => {
            const status = (user.id % 2 === 0)
                ? "Active"
                : "Inactive";

            return `${user.firstName} ${user.lastName} - ${status}`;

        });
        self.postMessage(result);

    }
    catch (error) {

        self.postMessage({
            error: error.message
        });

    }

};