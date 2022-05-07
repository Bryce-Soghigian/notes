# Using Minikube to create a cluster

## Goals
1. Learn what a kubernetes cluster is
2. Leran what minikube is
3. Start a kuberentes cluster using an online terminal




## Kubernetes clusters
**Kuberentes coordinates a high available cluster of computers that are connected to work as a single unit.**


Kubernetes automates the distribution and scheduling of application containers across a cluster in a more efficent way. 



### Kubernetes clusters contain
1. The Control plane
2. Nodes

The control plane is used to coordinate the cluster. And nodes are the workers that run applications. 


### The Control Plane
The control plane coordinates all activites in your cluster, such as scheduling applications, maintaining applications desired state, scaling applications and rolling out new updates.


### Kubernetes Nodes

A node is a VM or physical computer that serves as a worker machine in a kubernetes cluster. Each node has a KUBLET. WHich is responsible for managing the node and communicating with the kubernetes control plane. The nodes also have tools for handing container operations such as containerd or Docker. A Kubernetes cluster that handles production traffic should have aminimum of three nodes because if one node goes down, both an ETCD member and a control plan instance are lost and the redundancy is compromised. This golden number 3 shows up all throughout distrubted systems. 


The nodes communicate with the control plane via this platform called the Kubernetes API, which the control plane exposed End users can also use the kubernetes API to directly interact with the cluster. 



