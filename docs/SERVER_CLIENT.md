# Server and Client Model

## Roles

### Server
- Identity/authentication service.
- API gateway with request validation and rate limits.
- Work scheduler for CPU/GPU jobs.
- Storage service and job/result metadata.
- Metrics, structured logs, audit events, and health endpoints.
- Hardware abstraction layer so jobs can target the simulator, FPGA, or future accelerator.

### Client
- Desktop command-line tool and optional graphical control panel.
- Submits versioned jobs, polls or streams status, downloads results.
- Uses a typed SDK and explicit server capability discovery.
- Does not receive unrestricted host filesystem or device access.

## Protocol principles

- HTTPS/TLS for remote clients.
- Explicit protocol/API version in requests.
- Authenticated identities, scoped permissions, request quotas, and audit logging.
- Bounded input sizes and timeouts.
- Idempotency key for retryable job submissions.
- Results are checksummed and tagged with simulator/ISA build versions.
- Administrative APIs are separate from ordinary compute APIs.

## Example job lifecycle

1. Client authenticates.
2. Client asks server for supported ISA/GPU/runtime versions.
3. Client uploads a bounded program and input buffers.
4. Server validates format and resource limits.
5. Scheduler queues the job in a sandbox.
6. Simulator/accelerator runs with bounded memory and time budget.
7. Server stores logs, status, output, and checksums.
8. Client retrieves the result and verifies its checksum.

## Initial implementation order

1. Local command-line client against a local simulator.
2. Loopback-only server API with no unauthenticated remote access.
3. Authentication and job quotas.
4. Persistent job metadata and bounded artifact storage.
5. Remote client SDK.
6. Optional UI after the protocol stabilizes.

## Operational safeguards

Do not expose a prototype server publicly. Disable arbitrary shell execution, enforce payload limits, isolate jobs, redact secrets from logs, and test authentication and authorization before enabling remote access.
