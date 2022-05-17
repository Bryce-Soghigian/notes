# Roles
Kubernetes uses a Role based access control approach

## TLDR
Role based access control is a way of granting users granular access to kubernetes api resources. RBAC is a security design that restricts access to kubernetes resources based on the role the user holds. 

API Objects for configing RBAC: ROLE, CLUSTERROLE, ROLEBINDING, CLUSTERROLEBINDING.

Role/cluster role define what can be done, while who can do what is defined in RoleBinding/ClusterRoleBinding.


### Role
Role defines what can be done to kubernetes resources.
Some basic rules about roles LOL.
1. Role contains one or more rules that represent a set of permissions. 
2. Permissions are additive, there are no deny rules. If you want to deny somethign permissions you need to remove their permissions
3. Roles are namespaced. Meaning roles work within the constraints of a namespace. But dont worry about this too much ClusterRole pretty much eliminates this weakness. 
4. After creating a Role, you assign it to a user or group of users by creating a roleBinding

### ClusterRole
ClusterRole works the same as role, but there are applied to the cluster as whole.

1. ClusterRoles are not bound to a specific namespace. Clusterrole gives access across more than one namespace or all namespaces.
2. after creating a clusterrole you assign it to a user or group of users by creating a roleBinding or ClusterRoleBinding

Because Cluster roles are cluster scoped you can use cluster roles to control access to different kinds of resources than you can with Roles. 
1. Cluster Scoped Resources( Nodes, PersistentVolumes)
2. Non-Resource Endpoints( /healthz)
3. Namespaced Resources (pods accross the whole boi) across all namespaces. 

#### Default Cluster Role
cluster-admin: ClusterWideSuperUser
admin: Full access within a Namepace
edit: Read/Write within a Namespace
view: Read-only within a Namespace



### RoleBinding
Rolebinding is used for granting permission to a subject. 
1.Rolebinding honds a list of subjects(users, groups, or service accounts) and a reference to the role being granted.
2. Role and rolebinding are used in the namespace scope.
3. RoleBinding may reference any role in that namespace
4. After you create a binding you cannot change the role or ClusterRole that it refers to. If you do want to change the roleRef for a binding you need to remove the binding object and create a replacement.

### ClusterRoleBinding
ClusterRole and ClusterRoleBinding function like Role and Role Binding except they have a much wider scope. 
1. Rolebinding grants permissions within a specific namespace whereas a cluster Role Binding grants access cluster-wide and to multiple namespaces.
2. ClusterRoleBinding is a binding or accociating a Cluster With a Subject. 

