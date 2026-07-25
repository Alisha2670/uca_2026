const worker = new Worker("worker.js");
worker.onmessage = function(event) {
    const usersDiv = document.getElementById("users");
    usersDiv.innerHTML = "";
    if (event.data.error) {
        usersDiv.innerHTML = event.data.error;
        return;
    }
    if (event.data.length === 0) {
        usersDiv.innerHTML = "No users found";
        return;
    }
    event.data.forEach(user => {
        const p = document.createElement("p");
        p.textContent = user;
        usersDiv.appendChild(p);
    });

};

worker.onerror = function(error) {
    console.error(error);
};
worker.postMessage("Fetch Users");