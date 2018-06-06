/* This is the file locking table.  Like the filp table, it points to the
 * inode table, however, in this case to achieve advisory locking.
 */
EXTERN struct mnx_file_lock {
  short lock_type;		/* F_RDLOCK or F_WRLOCK; 0 means unused slot */
  mnx_pid_t lock_pid;		/* pid of the process holding the lock */
  struct inode *lock_inode;	/* pointer to the inode locked */
  mnx_off_t lock_first;		/* offset of first byte locked */
  mnx_off_t lock_last;		/* offset of last byte locked */
} file_lock[NR_LOCKS];
