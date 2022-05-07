# Kubernetes Deployments


## Objects
1. Learn aobut application Deployments
2. Deploy your first app on Kuberneteth kubectl

## Kubernetes Deployments 

Once you are running a kubernetes cluster you can deploy your containerized applications on top of it. To do so you create a Kuberenetes Deployemnt configuration. The deployment instructs kubernetes ahow to create and update instances of your application. Once you have created a deployment the kubernetes control plane schedules the application instances to run on individual nodes in the cluster.


Once the application instances are created a kubernetes deployment controller continuously monitors those instances. If the node hosting an instance goes down or is deleted, teh deployment controller replaces teh instance with an iinstance on another node in the cluster. This provides a self healing mechanism to address machine failure. 


