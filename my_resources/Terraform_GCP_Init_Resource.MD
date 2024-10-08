# Terraform Commands for Google Cloud

This document provides instructions for authenticating Terraform with Google Cloud and managing infrastructure.

## Prerequisites

Make sure you have the following installed:
- [Terraform](https://www.terraform.io/downloads.html)
- [Google Cloud SDK](https://cloud.google.com/sdk/docs/install)

## Authentication

Before creating infrastructure, Terraform must authenticate to Google Cloud. Follow these steps to set up your Application Default Credentials:

1. Open your terminal.
2. Use the `gcloud` CLI to log in:

   ```bash
   gcloud auth application-default login
   ```

3. A browser window will open, prompting you to log in to your Google Cloud account. After successful authentication, your terminal will display the path where the `gcloud` CLI saved your credentials:

   ```
   Credentials saved to file: [/Users/USER/.config/gcloud/application_default_credentials.json]
   ```

These credentials will be used by any library that requests Application Default Credentials (ADC).

## Initialize the Directory

Once authenticated, initialize the Terraform directory:

```bash
terraform init
```

## Format and Validate Configuration

To ensure your Terraform configuration is formatted correctly and valid, you can run the following commands:

1. Format your configuration:

   ```bash
   terraform fmt
   ```

2. Validate your configuration to check for syntax and internal consistency:

   ```bash
   terraform validate
   ```

   If the configuration is valid, Terraform will return a success message:

   ```
   Success! The configuration is valid.
   ```

## Create Infrastructure

To create the infrastructure defined in your Terraform configuration, run:

```bash
terraform apply
```

## Inspect State

After applying your configuration, Terraform writes data to a file called `terraform.tfstate`. This file contains the IDs and properties of the resources managed by Terraform, allowing it to update or destroy those resources in the future.

To inspect the current state, use the following command:

```bash
terraform show
```
```
