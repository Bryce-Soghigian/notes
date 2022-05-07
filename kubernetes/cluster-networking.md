# Cluster Networking

Networking is a central part of kubernetes, but it can be challenging to understand exactly how it expected to work. There are 4 distinct networking problems to address.


1. Highly coupled container to container communcations. This is solved by Pods and localhost communcations.
2. Pod to pod communcations. This is the primary focus of these notes.
3. Pod to service communications 
4. External to service communciations. 

Kubernetes is all about sharing machines between two apps bruh. Typically sharing machines requires ensuring that two apps do not try to use the sdame ports. Coordinating ports across multiple developers is very difficult to do at scale and exposes users to issues outside of their control. 


## Services, Load Balancing and Networking


## The kubernetes network model

Each pod gets its own IP address. This means you do not need to explicitly create links between pods and you almost never need to deal with mapping container ports to host ports. This creates a clean backaward compatible model where pods can be treated much like VMS or physical hosts from the perspetives of port allocation naming service discovery load balancing etc.

Kubernetes imposes 2 requirements on any nteworking implementation. 

1. Pods on a Node can communicate with all pods on all nodes without NAT(The process of translating a private ip to a public one)
2. Agents on a node( Daemons kublet) can communcate with all pods on that node.

Note: for those platforms that support pods running in the host network( Linux bruhj) 
1. pods in the host network of a node can communcate with all pods on all nodes without NAT


This model is not only less complex overall, but it is prinicipally compatible with the desire for kubernetes to enable low-friction porting of apps from VMs to containers. If your job perviously ran in a VM your VM had an ip and could talk to other Vms in your project. This is the same basic model. 

Kubernetes IP addresses exist at the POD scope. Containers withing a pod share their network namespaces. Including their IP address and MAC address. This means that containers within a pod can all reach each others ports on localhost. this also means that contianers within a pod must coordinate port useage. But this is no different from processes in a VM. This is called the IP-per-pod MODEL. 


How this is implemented is a detail of the particular container runtime in use. 

It is possible to request ports on the node itself which will forward to your POD. But this is a very niche operations. How that forwarding is implemented is also a detail of the container runtime. The pod itself is blind to the existence or non-existence of host ports. 


