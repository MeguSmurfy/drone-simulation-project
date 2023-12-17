# Team-010-69-hw4

Team 69, Section 010 - Dinh Quan Tran (tran1178) and Riley Findorff (findo009)

### Introduction 

This project is a simulation of a Drone delivery system on the UMN Campus. After launching the program, users can access a scheduling page where they can name and schedule deliveries. The scheduling page also allows users to choose the style of navigation the delivery drone will take, with options of A-star, BFS, DFS, and Djikstra’s pathfinding methods. You can also add instances of humans that wander around the delivery map. From the delivery visualization page you can see the 3D map of campus, along with our drone, a helicopter, a person, and any humans/packages you have added in the delivery scheduler. In this page you can choose to focus your camera on any entity (vehicles/humans/packages) that are on the map by using the “Change View” drop down menu. You can also choose to observe delivery specific objects through the “Change Observed Entity” tab, which contains a drop down menu of the Drone, all active packages, and all destinations. One can highlight all potential routes the drone can take with a checkbox on the right side, and the user can access the scheduling page through a button below it. The user can stop the schedule through the “Stop Simulation” button, and modify delivery speed through the slider. Lastly, there is also a notification system on the left side of the screen detailing the Drone’s percent distance to the delivery, along with more general status updates regarding the Drone and the package involved in the delivery.

### How to use the simulation

To run this project you need to be able to connect to the UMN CSE Lab Machines in some capacity. Once connected to a Lab machine, follow these instructions:

```
# Change to the project directory

cd /<filepath>

# Make the project
make -j

# Start the project (./build/web-app <port> <web folder>)
./build/bin/transit_service <port> /apps/transit_service/web/

```
Once you have started the server, you can access the scheduling page at http://127.0.0.1:[port]/schedule.html and the visualization of the delivery at http://127.0.0.1:[port] with [port] being the same port number you chose to launch the server on.
### Features of the simulation

### New feature (notifications)

Our new feature we added to our project is a notifications system. This system includes notifications for the Drone and Package(s) through the scheduling page. Each notification informs the user on the visualization page of the object’s respective status, i.e. “Drone has picked up <package_name>” or “Drone is delivering <package_name>”. The notifications are displayed by default, informing the user of the status of their delivery. The notification system also gives percentage intervals (every 25%) of how far the package has traveled along its route. This feature adds to the existing work by making use of a new type of class/design system, the observer pattern, and gives the user a way to track the progress of the drone(s). This can be helpful if one drone has multiple deliveries scheduled, or if there are multiple active drones that the user will want to be aware of. This user feature is automatically applied and is not user interactable.

### Sprint Retrospective

Here is the Youtube link:

Here is the Docker link:

And finally, here is the UML diagram:
![3081 010-69 Homework 4 Extension UML Diagram](https://github.umn.edu/umn-csci-3081-f23/team-010-69-hw4/blob/main/UML%20Diagram%20-%20team-010-69%20-%20Homework%204.png)
