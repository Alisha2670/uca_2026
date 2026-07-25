self.onmessage = function(event) {

    const users = event.data;
    const result = users.map(user => {
        const status = (user.id % 2 === 0) ? "Active" : "Inactive";
        return `${user.firstName} - ${status}`;
    });
    self.postMessage(result);

};