# Team-010-69-hw4

Team 69, Section 010 - Dinh Quan Tran (tran1178) and Riley Findorff (findo009)

### Introduction 

This project is a simulation of a Drone delivery system on the UMN Campus. Users are able to access a scheduling page to make deliveries with various pathing methods to robot recipients. On the viewing page the user is able to view deliveries and other entities wandering around (such as spawned humans and a helicopter). 

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

When the server is launched, the visualization page will become accessible and spawn in our Drone object, as well as a human and a helicopter. The scheduling page allows users to order deliveries by selecting the starting and ending destination on the UMN map. Before finalizing the delivery, the user can choose the style of navigation the delivery drone will take, with options of A-star, BFS, DFS, and Djikstra’s pathfinding strategies that can be employed. You can also add instances of humans that wander around the delivery map. When finalizing a delivery, the package is spawned into the delivery’s starting location, and a robot recipient is spawned at the package’s destination; both of these entities are created using factory class patterns. The drone will then determine its path with the strategy selected earlier, pick up the package, and complete the delivery. This movement can be seen on the delivery visualization page, which also shows the user real time updates of the progress of the drone and package. These notifications include general status updates and percentage values of the drone’s delivery progress.  You can also see the 3D map of campus, along with the  helicopter,  original person, and any humans/packages you have added in the delivery scheduler. You can choose to focus your camera on any entity (vehicles/humans/packages) that are on the map by using the “Change View” drop down menu. You can also choose to receive delivery notifications for specific objects through the “Change Observed Entity” tab, which contains a drop down menu of the Drone, all active packages, and all robots (standing at the package destination). One can highlight all potential routes the drone can take with a checkbox on the right side, and the user can access the scheduling page through a button below it. The user can stop the schedule through the “Stop Simulation” button, and modify delivery speed through the slider.


### New feature (notifications)

Our new feature we added to our project is a notifications system. This system includes notifications for the Drone and Package(s) through the scheduling page. Each notification informs the user on the visualization page of the object’s respective status, i.e. “Drone has picked up <package_name>” or “Drone is delivering <package_name>”. The notifications are displayed by default, informing the user of the status of their delivery. The notification system also gives percentage intervals (every 25%) of how far the entity has traveled along its route. You can focus your notifiations on a specific drone, package, or robot by selecting it in the "Chagne Observerd Entity" drop-down menu. This feature adds to the existing work by making use of a new type of class/design system, the observer pattern, and gives the user a way to track the progress of the drone(s). This can be helpful if one drone has multiple deliveries scheduled, or if there are multiple active drones that the user will want to be aware of. This user feature is automatically applied, but can be focused by the user through the aforementioned drop-down menu.

### Sprint Retrospective

We organized our sprints into two large blocks in which we would firstly create the UML and implement the observer classes (Sprint #1) then we would integrate the classes, document, cpplint, and complete the writeup (Sprint #2). This worked for us in keeping our project broken down into smaller manageable tasks, but we did not tend to follow the order of our sprint tasks. Due to our respective schedules, asynchronous work was a necessity. This meant that we could not be editing the same files simultaneously unless we were actively working together, reducing the efficacy of joint coding. Something that we could have done differently to improve upon our sprints would be to follow our outline more strictly and find more times to collaborate in-person instead of asynchronously on different sections.

Here is the Youtube link:

Here is the Docker link:

And finally, here is the UML diagram:
![3081 010-69 Homework 4 Extension UML Diagram](https://github.umn.edu/umn-csci-3081-f23/team-010-69-hw4/blob/main/UML%20Diagram%20-%20team-010-69%20-%20Homework%204.png)
