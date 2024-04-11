document.addEventListener("DOMContentLoaded", function() {
    const bookingForm = document.getElementById("booking-form");
    const ticketInfo = document.getElementById("ticket-info");
    const ticketDetails = document.getElementById("ticket-details");
  
    bookingForm.addEventListener("submit", function(event) {
      event.preventDefault();
      const formData = new FormData(bookingForm);
  
      const passengerName = formData.get("passengerName");
      const phoneNumber = formData.get("phoneNumber");
      const departureCity = formData.get("departureCity");
      const destinationCity = formData.get("destinationCity");
      const distance = formData.get("distance");
      const journeyDate = formData.get("journeyDate");
      const age = formData.get("age");
      const gender = formData.get("gender");
  
      // Calculate ticket price (just a placeholder, you can replace it with your own logic)
      const ticketPrice = parseFloat(distance) * 0.1;
  
      // Construct ticket details string with new lines and spaces
      const ticketInfoStr = `Your Ticket Details:\n
        Passenger Name: ${passengerName}\n
        Phone Number: ${phoneNumber}\n
        Departure City: ${departureCity}\n
        Destination City: ${destinationCity}\n
        Distance: ${distance} Km\n
        Journey Date: ${journeyDate}\n
        Age: ${age}\n
        Gender: ${gender}\n
        Ticket Price: Rs. ${ticketPrice.toFixed(2)}`;
  
      // Display ticket details
      ticketDetails.textContent = ticketInfoStr;
      ticketInfo.style.display = "block";
    });
  
    // Print ticket details to hello.txt
    const printTicketBtn = document.getElementById("print-ticket-btn");
    printTicketBtn.addEventListener("click", function() {
      const ticketDetailsStr = ticketDetails.textContent;
  
      fetch("hello.txt", {
        method: "POST",
        headers: {
          "Content-Type": "text/plain"
        },
        body: ticketDetailsStr
      }).then(response => {
        if (response.ok) {
          console.log("Ticket details saved to hello.txt");
          alert("Ticket details saved to hello.txt");
        } else {
          console.error("Failed to save ticket details");
          alert("Failed to save ticket details");
        }
      }).catch(error => {
        console.error("Error saving ticket details:", error);
        alert("Error saving ticket details");
      });
    });
  });
  