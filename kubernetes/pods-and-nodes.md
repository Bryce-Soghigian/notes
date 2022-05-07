# Viewing Pods and Nodes
## Objectives
1. Learn about kubernetes pods
2. Learn aobut kubernetes nodes
3. Troubleshoot deployed applications

## Kubernertes Pods
We created a deployment just before this. Kubernetes deployments are actually pods we created to host our application instance. A pod is a kubernetes abscraction that represents a group of one or more application containers such as Docker. Some Shared resources for those contianers include
1. Shared Storage such as Volumes
2. Networking as a unqiue cluster of IP addresses
3. Information about how to run each container such as teh contianer image or specific ports to use. 

A pod models an application specific "logical host" and can contain different application continaers which are relatively tightly coupled. For example a pod might include both the continer with your node JS app as well as adifferent contianre that feeds teh data to be published by that webserver thus run in a shared context on the same node. 

## Kubernetes Nodes
 A pod always runs on a Node. A node is a worker machine in Kubernetes and may be either a virtual or physical machine. Depending on the cluster. Each node is managed by the control plane. A node can have multiple pods and the kubernetes control plane automatically handles cheduling the pods across the nodes in the cluster. The control planes automatic scheduling takes into account the available resources on each Node

Each kuberenetes node runs at least
1. KUBELET. A process responsible for communication between the kubernetes control plan and the node. It manages the pods and the containers running on a machine. 
2. A container runtime like docker responsible for pulling the container image from a registry, upacking the container and running the applcation.


## Useful kubernetes troubleshooting commands.
1. kubectl get -- list resources
2. kubectl describe -- show detailed information about a resource
3. kubectl logs -- print the logs from a container in a pod
4. kubetl exec -- execute a command on a container in a pod.
