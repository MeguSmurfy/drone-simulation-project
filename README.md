# Team-010-69-hw4

Team 69, Section 010 - Dinh Quan Tran (tran1178) and Riley Findorff (findo009)

### Introduction 

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

Our new feature we added to our project is a notifications system. This system includes notifications for the Drone, Package, and/or Robot through the scheduling page. Each notification informs the user on the visualization page of the object’s respective status, i.e. “Drone has picked up <package_name>” or “Drone is delivering <package_name>”. The notifications are displayed by default, informing the user of the status of their delivery. This feature adds to the existing work by making use of a new type of class/design system, the observer pattern, and gives the user a way to track the progress of the drone(s). This can be helpful if one drone has multiple deliveries scheduled, or if there are multiple active drones that the user will want to be aware of. This user feature is automatically applied and is not user interactable.

### Sprint Retrospective

Here is the Youtube link:

Here is the Docker link:

And finally, here is the UML diagram:
![3081 010-69 Homework 4 Extension UML Diagram](https://github.umn.edu/umn-csci-3081-f23/team-010-69-hw4/blob/main/UML%20Diagram%20-%20team-010-69%20-%20Homework%204.png)
