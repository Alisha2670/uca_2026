const worker = new Worker("worker.js");

async function fetchUsers() {

    try {
        const response = await fetch("https://dummyjson.com/users");
        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }
        const data = await response.json();
        if (!data.users || data.users.length === 0) {
            throw new Error("No users returned from the API.");
        }
        worker.postMessage(data.users);
    }
    catch (error) {
        console.error("Error:", error.message);
    }

}

worker.onmessage = function(event) {
    event.data.forEach(user => {
        console.log(user);
    });

};

worker.onerror = function(error) {
    console.error("Worker Error:", error.message);
};

fetchUsers();