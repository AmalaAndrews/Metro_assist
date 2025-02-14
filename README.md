# Metro Travel Assistant


## Project Description
Metro Travel Assistant is a C-based Metro Reservation System designed for Bangalore Metro. This system allows users to book metro tickets, view their tickets, and check the metro map conveniently. The tickets are valid for 6 hours from the time of booking. The project ensures a smooth user experience with a menu-driven interface and data storage using text files.

## Features
1. **User Authentication**: Signup/Login system using a phone number.

2. **Ticket Booking**: Allows users to book metro tickets by selecting source and destination stations.

3. **Ticket Validation**: Ensures that tickets remain valid for only 6 hours.

4. **Metro Map Viewing**: Displays available metro stations for the Purple Line and Green Line.

5. **Ticket Management**: Users can view booked tickets or be notified if none exist.

6. **User-Friendly Interface**: Simple, interactive, and menu-driven system.

7. **Data Storage**: Ticket details are stored in .txt files for record-keeping.

8. **Secure Authentication**: Ensures that users can only access their own tickets.

9. **Graceful Exit**: Displays a thank-you message before exiting the program.

## Technologies Used
- Programming Language: C

- File Handling: .txt files for storing user credentials and ticket details.

- Dynamic Memory Allocation: Used for efficient data management.

- Structured Programming: Modular design with separate files for authentication, booking, and ticket management.

## Installation
1. Clone the repository:
   git clone git@github.com:AmalaAndrews/Metro_assist.git
2. Navigate to the project directory:
   cd Metro_assist
3. Compile the C program:
   gcc metro_travel.c -o metro_travel
4. Run the program:
   ./metro_travel

## How to Use
## 1. User Authentication

- **New User Registration**: Enter your phone number to create an account.

- **Existing User Login**: Log in using your registered phone number.

## 2. Booking a Ticket

- Select Purple Line or Green Line.

- Enter a valid source and destination station.

- Specify the number of passengers (1-6).

- The system calculates the fare and displays the ticket details.

## 3. Viewing Booked Tickets

- If tickets exist, they will be displayed with route, fare, and passenger details.

- If no tickets are available, an appropriate message is shown.

## 4. Viewing Metro Map

- Displays all stations under the Purple Line and Green Line.

## 5. Exiting the System

- Displays a Thank You message before exiting.

## Project Structure
Metro_assist/
│── metro_travel.c         # Main C program
│── stations.h             # Header file for metro stations
│── user_auth.c            # Handles user authentication
│── ticket_booking.c       # Manages ticket booking
│── ticket_viewing.c       # Displays booked tickets
│── metro_map.c            # Displays metro stations
│── data_storage.c         # Manages file storage operations
│── README.md              # Project documentation
│── tickets.txt            # Stores booked ticket details

## Contributing
Contributions are welcome! If you’d like to improve the project:

1. Fork the repository.

2. Create a new branch:

   git checkout -b feature-name

3. Commit your changes:

   git commit -m "Add feature-name"

4. Push the changes:

  git push origin feature-name

5. Open a Pull Request.

## License
This project is open-source and available under the MIT License.
