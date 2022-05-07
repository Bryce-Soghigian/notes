# Command Line tool Kubectl

Kubernetes provides a command line tool for communciating with a kubernetes clusters control plane. Using the kuberenetes api.

So when researching what info we can access via kubectl we also need to think about what info the api exposes about the control plane. 

## Syntax
Use the Following syntax to run kubectl commands from your terminal window. 

```
kubectl [command] [type] [NAME] [flags]
```

where command, type, name and flags are:

1. command: Specifies the operation that you want to perform on one or more resources for example create, get, describe, delete
2. TYPE: Specifies the resource type. Resource types are case insensitive and you can specify them in single or in plural forms.
3. Name: Specifies the name of the resource. If name is emitted all sources of the specified type are displayed. 
4. Flags can be used to specify specific information on things.

