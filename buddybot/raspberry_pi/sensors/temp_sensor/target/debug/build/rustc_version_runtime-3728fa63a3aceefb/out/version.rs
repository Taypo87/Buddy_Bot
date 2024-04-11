
            /// Returns the `rustc` SemVer version and additional metadata
            /// like the git short hash and build date.
            pub fn version_meta() -> VersionMeta {
                VersionMeta {
                    semver: Version {
                        major: 1,
                        minor: 77,
                        patch: 2,
                        pre: vec![],
                        build: vec![],
                    },
                    host: "aarch64-unknown-linux-gnu".to_owned(),
                    short_version_string: "rustc 1.77.2 (25ef9e3d8 2024-04-09)".to_owned(),
                    commit_hash: Some("25ef9e3d85d934b27d9dada2f9dd52b1dc63bb04".to_owned()),
                    commit_date: Some("2024-04-09".to_owned()),
                    build_date: None,
                    channel: Channel::Stable,
                }
            }
            